#include "platon/merkle/merkle_tree.hpp"
#include <vector>
#include "platon/merkle/hash.hpp"
#include "unit_test.hpp"
std::vector<h256> test_data = {
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000000")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000001")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000002")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000003")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000004")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000005")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000006")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000007")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000008")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000009")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000000a")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000000b")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000000c")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000000d")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000000e")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000000f")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000010")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000011")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000012")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000013")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000014")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000015")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000016")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000017")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000018")),
    h256(std::string_view(
        "0x0000000000000000000000000000000000000000000000000000000000000019")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000001a")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000001b")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000001c")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000001d")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000001e")),
    h256(std::string_view(
        "0x000000000000000000000000000000000000000000000000000000000000001f"))};

h256 test_sha256_root = h256(std::string_view(
    "0x2b10d4f060de0bbfaa4fef9715096f61899739383c26ac45ee64999c5ba16f2a"));

platon::merkle::MerkleTree<"s"_n, platon::merkle::hash::Sha256, 32> tree;

TEST_CASE(merkle_tree, insert) {
  h256 root;
  for (const auto &h : test_data) {
    root = tree.Insert(h).first;
  }
  ASSERT_EQ(test_sha256_root, root, "expect:", test_sha256_root.toString(),
            "actual:", root.toString());
}

TEST_CASE(merkle_tree, getleaf) {
  for (size_t i = 0; i < test_data.size(); i++) {
    auto leaf = tree.GetLeaf(0, i);
    ASSERT_EQ(test_data[i], leaf, "expect:", test_data[i].toString(),
              "leaf:", leaf.toString());
  }
}

TEST_CASE(merkle_tree, proof) {
  for (size_t i = 0; i < test_data.size(); i++) {
    auto proof = tree.GetProof(i);
    ASSERT(tree.Verify(test_data[i], proof.first, proof.second),
           test_sha256_root.toString());
  }
}

UNITTEST_MAIN() {
  RUN_TEST(merkle_tree, insert);
  RUN_TEST(merkle_tree, getleaf);
  RUN_TEST(merkle_tree, proof);
}