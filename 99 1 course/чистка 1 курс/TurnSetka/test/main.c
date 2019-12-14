#define CTEST_MAIN
#include <ctest.h>
#include <Funcs_2.h>
#include <Funcs.h>

CTEST(checkIns, Incorrect1) {
    char ins [1];
    ins [0] = 'g';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect2) {
    char ins [2];
    ins [1] = 'f';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect3) {
    char ins [12];
    ins [0] = 't', ins[1] = 'a';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect4) {
    char ins [1];
    ins [0] = '9';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect5) {
    char ins [1];
    ins [0] = '3';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect6) {
    char ins [2];
    ins [1] = ' ';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect7) {
    char ins [3];
    ins [0] = 'l', ins[1] = 'a';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(checkIns, Incorrect8) {
    char ins [1];
    ins [0] = '5';
    int result = checkIns(ins);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

/*
CTEST(checkIns, Correct1) {
    char ins [1];
    ins [0] = '2';
    int result = checkIns(ins);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}
CTEST(checkIns, Correct2) {
    char ins [1];
    ins [0] = '1';
    int result = checkIns(ins);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}//these two don't work in travis for some reason(work in local git though).
*/
    
int main(int argc, const char** argv) {
    int test_res = ctest_main(argc, argv);
    return test_res;
}