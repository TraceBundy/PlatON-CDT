
#undef NDEBUG
#include "platon/platon.hpp"
#include "unit_test.hpp"

using namespace platon;

TEST_CASE(uint256, assign) {
  const char *fn = "assign";
  std::uint256_t orign(30);
  std::uint256_t other;

  {
    GasUsed(__LINE__, fn);
    orign = other;
  }

  ASSERT_EQ(orign, orign);
}

TEST_CASE(uint256, add) {
  const char *fn = "add";
  std::uint256_t orign(202);
  std::uint256_t other(243);

  {
    GasUsed(__LINE__, fn);
    orign = orign + other;
  }

  ASSERT_EQ(orign, std::uint256_t(445));
  orign += other;
  ASSERT_EQ(orign, std::uint256_t(688));
}

TEST_CASE(uint256, sub) {
  const char *fn = "sub";
  std::uint256_t orign(202);
  std::uint256_t other(24);

  {
    GasUsed(__LINE__, fn);
    orign = orign - other;
  }

  ASSERT_EQ(orign, std::uint256_t(178));
  orign -= other;
  ASSERT_EQ(orign, std::uint256_t(154));
}

TEST_CASE(uint256, multip) {
  const char *fn = "multip";
  std::uint256_t orign(202);
  std::uint256_t other(24);

  {
    GasUsed(__LINE__, fn);
    orign = orign * other;
  }

  ASSERT_EQ(orign, std::uint256_t(4848));
  orign /= other;
  ASSERT_EQ(orign, std::uint256_t(202));
}

TEST_CASE(uint256, division) {
  const char *fn = "division";
  std::uint256_t orign(202);
  std::uint256_t other(24);

  {
    GasUsed(__LINE__, fn);
    orign = orign / other;
  }

  ASSERT_EQ(orign, std::uint256_t(8));
  orign /= other;
  ASSERT_EQ(orign, std::uint256_t(0));
}

TEST_CASE(uint256, mod) {
  const char *fn = "mod";
  std::uint256_t orign(503);
  std::uint256_t other(10);

  {
    GasUsed(__LINE__, fn);
    orign = orign % other;
  }

  ASSERT_EQ(orign, std::uint256_t(3));
  orign += 2;
  orign %= other;
  ASSERT_EQ(orign, std::uint256_t(5));
}

TEST_CASE(uint256, and) {
  const char *fn = "and";
  std::uint256_t orign(503);
  std::uint256_t other(100);

  {
    GasUsed(__LINE__, fn);
    orign = orign & other;
  }

  ASSERT_EQ(orign, std::uint256_t(100));
  orign = orign & 0xff;
  ASSERT_EQ(orign, std::uint256_t(100));
}

TEST_CASE(uint256, or) {
  const char *fn = "or";
  std::uint256_t orign(503);
  std::uint256_t other(100);

  {
    GasUsed(__LINE__, fn);
    orign = orign | other;
  }

  ASSERT_EQ(orign, std::uint256_t(503));
  orign = orign | 0xff;
  ASSERT_EQ(orign, std::uint256_t(511));
}

TEST_CASE(uint256, xor) {
  const char *fn = "xor";
  std::uint256_t orign(503);
  std::uint256_t other(100);

  {
    GasUsed(__LINE__, fn);
    orign = orign ^ other;
  }

  ASSERT_EQ(orign, std::uint256_t(403));
  orign = orign ^ 0xff;
  ASSERT_EQ(orign, std::uint256_t(364));
}

TEST_CASE(uint256, left_shift) {
  const char *fn = "left_shift";
  std::uint256_t orign(503);
  std::uint256_t other(100);

  {
    GasUsed(__LINE__, fn);
    orign = orign << 6;
  }

  ASSERT_EQ(orign, std::uint256_t(32192));
  orign = other << 2;
  ASSERT_EQ(orign, std::uint256_t(400));
}

TEST_CASE(uint256, right_shift) {
  const char *fn = "right_shift";
  std::uint256_t orign(503);
  std::uint256_t other(100);

  {
    GasUsed(__LINE__, fn);
    orign = orign >> 2;
  }

  ASSERT_EQ(orign, std::uint256_t(125));
  orign = other >> 2;
  ASSERT_EQ(orign, std::uint256_t(25));
}

TEST_CASE(int256_t, neg) {
  std::int256_t orign(503);
  std::int256_t result = -orign;
  ASSERT_EQ(result, std::int256_t(-503));
}

TEST_CASE(int256_t, add) {
  const char *fn = "add";
  std::int256_t orign(202);
  std::int256_t other(-243);

  {
    GasUsed(__LINE__, fn);
    orign = orign + other;
  }

  ASSERT_EQ(orign, std::int256_t(-41));
  orign += other;
  ASSERT_EQ(orign, std::int256_t(-284));
}

TEST_CASE(int256_t, compare) {
  const char *fn = "compare";
  std::int256_t orign(202);
  std::int256_t other(-243);
  bool compare_result;

  {
    GasUsed(__LINE__, fn);
    compare_result = orign < other;
  }

  ASSERT_EQ(compare_result, false);
  orign += other;
  compare_result = orign < other;
  ASSERT_EQ(compare_result, false);
  orign += other;
  compare_result = orign < other;
  ASSERT_EQ(compare_result, true);
}

TEST_CASE(uint256, overflow) {
  std::uint256_t orign =
      "41234123412341234123412341234123412341234123412341234123412341234123412341234"_uint256;
  std::uint256_t other = orign;
  std::uint256_t result = orign + other;
  ASSERT_EQ(
      result,
      "82468246824682468246824682468246824682468246824682468246824682468246824682468"_uint256);
}

TEST_CASE(uint512, overflow) {
  const char *fn = "overflow";
  std::uint512_t orign;

  {
    GasUsed(__LINE__, fn);
    orign =
        "3412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234"_uint512;
  }

  std::uint512_t other = orign;
  std::uint512_t result = orign + other;
  ASSERT_EQ(
      result,
      "6824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468"_uint512);
}

TEST_CASE(uint256, exp) {
  std::uint256_t left(10);
  std::uint256_t right(5);
  std::uint256_t mod(17);
  const char *fn = "exp";
  std::uint256_t result;

  {
    GasUsed(__LINE__, fn);
    result = Exp(left, right, mod);
  }

  ASSERT_EQ(result, std::uint256_t(6));
}

TEST_CASE(uint256, encode) {
  const char *fn = "encode";
  std::uint256_t result;
  std::vector<uint8_t> test_bytes{0x01, 0x02};

  {
    GasUsed(__LINE__, fn);
    result.FromBigEndian(test_bytes);
  }

  ASSERT_EQ(result, std::uint256_t(258));

  std::vector<uint8_t> new_bytes;
  {
    GasUsed(__LINE__, fn);
    new_bytes = result.ToBigEndian();
  }

  ASSERT_EQ(new_bytes, test_bytes);
}

UNITTEST_MAIN() {
  RUN_TEST(uint256, assign);
  RUN_TEST(uint256, add);
  RUN_TEST(uint256, sub);
  RUN_TEST(uint256, multip);
  RUN_TEST(uint256, division);
  RUN_TEST(uint256, mod);
  RUN_TEST(uint256, and);
  RUN_TEST(uint256, or);
  RUN_TEST(uint256, xor);
  RUN_TEST(uint256, left_shift);
  RUN_TEST(uint256, right_shift);
  RUN_TEST(int256_t, neg);
  RUN_TEST(int256_t, add);
  RUN_TEST(int256_t, compare);
  RUN_TEST(uint256, overflow);
  RUN_TEST(uint512, overflow);
  RUN_TEST(uint256, exp);
  RUN_TEST(uint256, encode);
}