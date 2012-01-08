# include <stdio.h>
# include <string.h>
# include <assert.h>

/*
 * Write a function expand(s1, s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent
 * complete list abc...xyz in s2. Allow for letters of either
 * case and digits and be prepared to handle cases like a-b-c
 * and a-z0-9 and -a-z. Arrange that a leading or trailing -
 * is taken literally.
 */

# define MAXSTRINGLENGTH 50

void expand(char s1[], char s2[]);

void assert_equal(char expected[], char got[]) {
    int length_expected = strlen(expected), length_got = strlen(got);

    assert(length_expected == length_got);
    int i;

    for (i = 0; i < length_expected; i++) {
        assert(expected[i] == got[i]);
    }
}

void test_expand_a_z() {
    char s1[MAXSTRINGLENGTH] = "a-z", s2[MAXSTRINGLENGTH];
    expand(s1, s2);
    assert(26 == strlen(s2));
    assert_equal("abcdefghijklmnopqrstuvwxyz", s2);
}

void test_expand_A_Z() {
    char s1[MAXSTRINGLENGTH] = "A-Z", s2[MAXSTRINGLENGTH];
    expand(s1, s2);
    assert(26 == strlen(s2));
    assert_equal("ABCDEFGHIJKLMNOPQRSTUVWXYZ", s2);
}

void test_expand_0_9() {
    char s1[MAXSTRINGLENGTH] = "0-9", s2[MAXSTRINGLENGTH];
    expand(s1, s2);
    assert(10 == strlen(s2));
    assert_equal("0123456789", s2);
}

void test_expand_hifen_a_z() {
    char s1[MAXSTRINGLENGTH] = "-a-z", s2[MAXSTRINGLENGTH];
    expand(s1, s2);
    assert(27 == strlen(s2));
    assert_equal("-abcdefghijklmnopqrstuvwxyz", s2);
}

int main (int argc, char const* argv[]) {
    test_expand_a_z();
    test_expand_A_Z();
    test_expand_0_9();
    test_expand_hifen_a_z();
    return 0;
}

void expand(char s1[], char s2[]) {
    int i, c, init = (s1[0] == '-' ? 1 : 0);

    if (init > 0) {
        s2[0] = s1[0];
    }

    for (i = init, c = s1[init]; c <= s1[init + 2]; i++, c++) {
        s2[i] = c;
    }

    s2[i] = '\0';
}
