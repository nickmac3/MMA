// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2019, 2ACoin Developers
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {  
{       0, "be58c8366a1f8a4b352f69064b588494c7f4dbd07e19821d7861945b2f85a2dd"},
{    5000, "f4925e32a226889b515e82f904ab1d0f1d2bfe762b25f9d0ad827bdc08a2b422"},
{   10000, "fd56d9647b3012dd30a0d12705b68f3c52af195f0a5cd66f8e8aa5112b41e05c"},
{   15000, "09c6ff3a2130cd175a9cc2cd00485d484ec0ed647d2c79575f01e6b42335df4b"},
{   20000, "7fa0e1e9f2efe37b7f847ef77c8799381d3c73ae4703dc12b0590f071e4b7cc3"},
{   25000, "1658532624c18f326092c8014ad69c1d565045bd51d7f7d0ff0abc11bf036049"},
{   30000, "3ec3ce36f0134655c80b1c9e9977d03c85cf5675ea09f08e54a2245f2d6c4406"},
{   35000, "81610d559594a2a8d9b87b0ef051a06a6e40a0cd2d88fc312e1cd1733de0b3d2"},
{   40000, "b82f45521363c28c8dc5d1a0f89b757fde2abb67b02b98c24c65f4b14b839264"},
{   45000, "dfe435831de24aca7fd1b44fabbe424f04f1b6412b39204ef71245c700a938a0"},
{   50000, "0f0d57dd7cde882bd7beee55aeef3eb86d79005f474636fbacf8529cfc7c4dfb"},
{   55000, "7a04ff3aa5b75acb9357fc2622156ab8520859b96520e43769be75968c6b0e50"},
{   60000, "0cfd1499436a6b949cf7a1e5c2d2c653db932bb0348af63e35bead4f22f3de6e"},
{   65000, "a0e5f7160d7a5741da62669deea099c240993021afeb427fdd39fe0ee6528837"},
{   70000, "d8476e2e5ab742e1b0d9a6a30d9fcc28220a055489dcab9fd3b8e57f74e40988"},
{   75000, "f9e116fd0948a874406eb77f39e58957ae39d71a5dccf0962f6444264dcc9d33"},
{   80000, "3ca4969286e1aa8be7b9c6ad7c2e518e011bdc17a6ebacd78d1e8bb39bbf7579"},
{   85000, "8cec855eda8f09ca4cd17c51d1229353d64e37ed8dff13649ceb1946f29a9710"},
{   90000, "79b75442f1aa3341fb26ef341a60b359a09d878980185a666141796290c0f07f"},
{   95000, "5cc0d391a5c713cba3e0c59b866e1f21c9103842007d783fafae3b362fae283b"},
{  100000, "189d9f1aed0ace708198cc0c55c2798ca3ca735d75cbd521e34fe51fec83dc87"},
{  105000, "8ee7a6e15e809dfdf4198663129a1b0045ac9533f2f06990c841ac2552245160"},
{  110000, "8f5d4f18725b59baaf8cc5ffe2254d799e071a8397f0d58465e5c87cbfa222e4"},
{  115000, "632150629884932bf8e605cc4af7b6c946e8c19881b91462b09b6a90280e0a0b"},
{  120000, "4cc75976755e39c4d07f7ae589d6519f78aaa03d3a51cefb1913109e4fdf191b"},
{  125000, "20dee6838667205fd83325f5a4d4414b976271d0f26604cf813bb29c3efe3d72"},
{  130000, "a2c5daef1fc1e9af51d17242bb313f69fab9168df9da26664052251ad07191e8"},
{  135000, "564c4e96d57a68b5c37d55e650cdb98281cca9d93830d3330154e01708bdf19b"},
{  140000, "1706ae092dc4aa9f239d56b2da3d7b2d7b43678bfe39bc397d048da7a43c5d4a"},
{  145000, "f389bc8313959d961ae34d52472fb3935e02aba8ae89742b881ea68c363c0540"},
{  150000, "ac0621d0cd46a8781d6b73f8e5301a68cb85ad65a5b6fa007ae26d5a5e737c95"},
{  155000, "140f2b4a72539a1dd7930ad7dec9bdbf0508997012c5767a2b3cbcccef643043"},
{  160000, "64dd44e638ecb5c551217250eafaffa09954a9dd3fc7d2909ed6982f02d16e5f"},
{  165000, "81ed7d67abcc86e302a9c7d7f289660162330d1925f39459e719567683e70fe1"},
{  170000, "07568e1b2747ddd1a403c3f936adf121644e468b85498c8ac34902408f307f51"},
{  175000, "f4747fec610013bbe67e4e3bb06bedad1b8ee1e86189a63330309d12c523a106"},
{  180000, "66592151497a8d103b9e32ebf1f4f390496e7525a20c44331994df4dc8a3d56b"},
{  185000, "027d96d4bebedfd413f07645eecf9b163c3fac71262496e829c05cb5d52439d0"},
{  190000, "13fdded80f99b3f1f70bfe120348fa923cd1b81baf2fab595f5ad82af58ea3b6"},
{  195000, "8954e615af112889d622ec3516670f6f862482d0d9e757040df4bbe771063ce0"},
{  200000, "b7ae0128ad23ec3d7880b6d41b7ab51a00cefa4cb84e68a94941dbd2e1b19d61"},
{  205000, "187df654c6bdf824e1002a19d2d858454ab4abc7d444677e186b9ecf883fc269"},
{  210000, "2978d7f79fbf9318082810f789f8c46f966e2647253c6d7206d73a11273fca16"},
{  215000, "221e2e160e842ae01056bf82104fc1685b47044d1a21348170793d6abf5e6902"},
{  220000, "05a8fe603dab53278d787ebc7cadef30ded5b17e3a9b13dda78d6ee7212d2543"},
{  225000, "130b88386742f74e6b042b35910afced9c9cb2970ba0dbe5033eddbb1f64f590"},
{  230000, "cb04f89c948a68a66641dab0be375b4285a17101f2b6d7ba12a1164d9df6a405"},
{  235000, "541f937266d63be88cb0ec66e2ec76e9d4d03443faef92060b9577bd9bcef027"},
{  240000, "6b37cbdac5bd82501659897b32dce6e8b3397a5d604fe1a0fbe38212cc8aed01"}
};
}
