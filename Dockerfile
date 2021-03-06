# daemon runs in the background
# run something like tail /var/log/2acoind/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/2acoind:/var/lib/2acoind -v $(pwd)/wallet:/home/2acoin --rm -ti 2acoin:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG 2ACOIN_BRANCH=master
ENV 2ACOIN_BRANCH=${2ACOIN_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/2acoin/2acoin.git /src/2acoin && \
    cd /src/2acoin && \
    git checkout $2ACOIN_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/2ACoind /usr/local/bin/2ACoind && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zedwallet /usr/local/bin/zedwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/2ACoind && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zedwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/2acoin && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the 2acoind service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/2acoind 2acoind && \
    useradd -s /bin/bash -m -d /home/2acoin 2acoin && \
    mkdir -p /etc/services.d/2acoind/log && \
    mkdir -p /var/log/2acoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/2acoind/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/2acoind/run && \
    echo "cd /var/lib/2acoind" >> /etc/services.d/2acoind/run && \
    echo "export HOME /var/lib/2acoind" >> /etc/services.d/2acoind/run && \
    echo "s6-setuidgid 2acoind /usr/local/bin/2ACoind" >> /etc/services.d/2acoind/run && \
    chmod +x /etc/services.d/2acoind/run && \
    chown nobody:nogroup /var/log/2acoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/2acoind/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/2acoind/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/2acoind" >> /etc/services.d/2acoind/log/run && \
    chmod +x /etc/services.d/2acoind/log/run && \
    echo "/var/lib/2acoind true 2acoind 0644 0755" > /etc/fix-attrs.d/2acoind-home && \
    echo "/home/2acoin true 2acoin 0644 0755" > /etc/fix-attrs.d/2acoin-home && \
    echo "/var/log/2acoind true nobody 0644 0755" > /etc/fix-attrs.d/2acoind-logs

VOLUME ["/var/lib/2acoind", "/home/2acoin","/var/log/2acoind"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/2acoin export HOME /home/2acoin s6-setuidgid 2acoin /bin/bash"]
