#include <limits.h>
#include <gtest/gtest.h>
#include "Multiplier.h"
#include <cmath>


class MultiplierTest : public ::testing::Test {

protected:
    int call_sign(Multiplier* ml, int n) {
        return ml->sign(n);
    }

    int call_abs(Multiplier* ml, int n) {
        return ml->abs(n);
    }

    Accumulator& get_mAc(Multiplier* ml) {
        return ml->mAc;
    }

};

namespace {

    TEST(Multiplier, mul) {
        // 前準備
        int n1 = 8;
        int n2 = 5;
        Multiplier ml;
        // 実行
        int mul = ml.mul(n1, n2);
        // 検証
        ASSERT_EQ(n1*n2, mul);
    }

    TEST(Multiplier, div) {
        // 前準備
        int n1 = 8;
        int n2 = 5;
        Multiplier ml;
        // 実行
        int div = ml.div(n1, n2);
        // 検証
        ASSERT_EQ(n1/n2, div);
    }

    TEST_F(MultiplierTest, sign_plus) {
        // 前準備
        int n = 8;
        Multiplier ml;
        // 実行
        int s = call_sign(&ml, n);
        // 検証
        ASSERT_EQ(n<0, s);
    }

    TEST_F(MultiplierTest, sign_minus) {
        // 前準備
        int n = -8;
        Multiplier ml;
        // 実行
        int s = call_sign(&ml, n);
        // 検証
        ASSERT_EQ(n<0, s);
    }

    TEST_F(MultiplierTest, abs_plus) {
        // 前準備
        int n = 8;
        Multiplier ml;
        // 実行
        int a = call_abs(&ml, n);
        // 検証
        ASSERT_EQ(abs(n), a);
    }

    TEST_F(MultiplierTest, abs_minus) {
        // 前準備
        int n = -8;
        Multiplier ml;
        // 実行
        int a = call_abs(&ml, n);
        // 検証
        ASSERT_EQ(abs(n), a);
    }

}
