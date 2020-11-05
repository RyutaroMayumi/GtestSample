#include <limits.h>
#include <gtest/gtest.h>
#include "Accumulator.h"


class AccumulatorTest : public ::testing::Test {

protected:
    int call_accum(Accumulator* ac, int n) {
        return ac->accum(n);
    }
    
    int call_reset(Accumulator* ac) {
        return ac->reset();
    }

    int get_mVal(Accumulator* ac) {
        return ac->mVal;
    }

};

namespace {

    TEST(Accumulator, add) {
        // 前準備
        int n1 = 8;
        int n2 = 5;
        Accumulator ac;
        // 実行
        int add = ac.add(n1, n2);
        // 検証
        ASSERT_EQ(n1+n2, add);
    }

    TEST(Accumulator, sub) {
        // 前準備
        int n1 = 8;
        int n2 = 5;
        Accumulator ac;
        // 実行
        int sub = ac.sub(n1, n2);
        // 検証
        ASSERT_EQ(n1-n2, sub);
    }

    TEST_F(AccumulatorTest, accum) {
        // 前準備
        int n = 8;
        Accumulator ac;
        // 実行
        int accum = call_accum(&ac, n);
        // 検証
        ASSERT_EQ(n, accum);
    }

    TEST_F(AccumulatorTest, reset) {
        // 前準備
        int n = 8;
        Accumulator ac;
        // 実行
        int accum = call_accum(&ac, n);
        int zero = call_reset(&ac);
        // 検証
        ASSERT_EQ(0, zero);
    }

}
