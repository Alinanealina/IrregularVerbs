#define CTEST_MAIN
#include "console.h"
#include <ctest.h>
const int N = 8, M = 9;

CTEST(W_Peshka, Correct_p_forward)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '2';
    move[3] = '-';
    move[4] = 'e';
    move[5] = '4';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[1][4] = 'p';
    a[3][4] = ' ';
    int result = move_p_w(a, move, 1, 4, 3, 4);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Peshka, Correct_p_forward)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '7';
    move[3] = '-';
    move[4] = 'e';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[6][4] = 'P';
    a[5][4] = ' ';
    int result = move_p_b(a, move, 6, 4, 5, 4);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Peshka, Correct_p_hack)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '2';
    move[3] = 'x';
    move[4] = 'f';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[1][4] = 'p';
    a[2][5] = 'P';
    int result = move_p_w(a, move, 1, 4, 2, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Peshka, Correct_p_hack)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '7';
    move[3] = 'x';
    move[4] = 'f';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[6][4] = 'P';
    a[5][5] = 'p';
    int result = move_p_b(a, move, 6, 4, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Rook, Correct_Rook_f)
{
    char move[6], a[N][M];
    move[0] = 'R';
    move[1] = 'a';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][0] = 'r';
    a[2][0] = ' ';
    int result = move_r_w(a, move, 0, 0, 2, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Rook, Correct_Rook_f)
{
    char move[6], a[N][M];
    move[0] = 'R';
    move[1] = 'a';
    move[2] = '8';
    move[3] = '-';
    move[4] = 'a';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][0] = 'R';
    a[5][0] = ' ';
    int result = move_r_b(a, move, 7, 0, 5, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Rook, Correct_Rook_h)
{
    char move[6], a[N][M];
    move[0] = 'R';
    move[1] = 'a';
    move[2] = '1';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][0] = 'r';
    a[2][0] = 'R';
    int result = move_r_w(a, move, 0, 0, 2, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Rook, Correct_Rook_h)
{
    char move[6], a[N][M];
    move[0] = 'R';
    move[1] = 'a';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][0] = 'R';
    a[5][0] = 'r';
    int result = move_r_b(a, move, 7, 0, 5, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Horse, Correct_Knight_f)
{
    char move[6], a[N][M];
    move[0] = 'N';
    move[1] = 'b';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][1] = 'N';
    a[2][0] = ' ';
    int result = move_n_b(a, move, 0, 1, 2, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Horse, Correct_Knight_h)
{
    char move[6], a[N][M];
    move[0] = 'N';
    move[1] = 'b';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][1] = 'N';
    a[5][0] = 'r';
    int result = move_n_b(a, move, 7, 1, 5, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Bishop, Correct_Bishop_f)
{
    char move[6], a[N][M];
    move[0] = 'B';
    move[1] = 'c';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][2] = 'b';
    a[2][0] = ' ';
    int result = move_b_w(a, move, 0, 2, 2, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Bishop, Correct_Bishop_h)
{
    char move[6], a[N][M];
    move[0] = 'B';
    move[1] = 'c';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][2] = 'B';
    a[5][0] = 'b';
    int result = move_b_b(a, move, 7, 2, 5, 0);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Queen, Correct_Queen_f)
{
    char move[6], a[N][M];
    move[0] = 'Q';
    move[1] = 'd';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'd';
    move[5] = '2';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][3] = 'q';
    a[1][3] = ' ';
    int result = move_q_w(a, move, 0, 3, 1, 3);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Queen, Correct_Queen_h)
{
    char move[6], a[N][M];
    move[0] = 'Q';
    move[1] = 'd';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'd';
    move[5] = '2';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[4][7] = 'Q';
    a[4][3] = 'p';
    int result = move_q_b(a, move, 4, 7, 4, 3);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_King, Correct_King_f)
{
    char move[6], a[N][M];
    move[0] = 'K';
    move[1] = 'e';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'e';
    move[5] = '2';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][4] = 'k';
    a[1][4] = ' ';
    int result = move_k_w(a, move, 0, 4, 1, 4);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_King, Correct_King_h)
{
    char move[6], a[N][M];
    move[0] = 'K';
    move[1] = 'e';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'd';
    move[5] = '7';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][4] = 'K';
    a[6][3] = 'n';
    int result = move_k_b(a, move, 7, 4, 6, 3);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

// INCORRECT

CTEST(B_Peshka, InCorrect_p_forward)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '7';
    move[3] = '-';
    move[4] = 'e';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[6][4] = 'P';
    a[5][4] = 'p';
    int result = move_p_b(a, move, 6, 4, 5, 4);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Peshka, InCorrect_p_hack)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '2';
    move[3] = 'x';
    move[4] = 'f';
    move[5] = '4';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[1][4] = 'p';
    a[3][5] = ' ';
    int result = move_p_w(a, move, 1, 4, 3, 5);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Rook, InCorrect_Rook_f)
{
    char move[6], a[N][M];
    move[0] = 'R';
    move[1] = 'a';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][0] = 'R';
    a[2][0] = 'n';
    int result = move_r_w(a, move, 0, 0, 2, 0);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Rook, InCorrect_Rook_h)
{
    char move[6], a[N][M];
    move[0] = 'R';
    move[1] = 'a';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][0] = 'R';
    a[3][0] = ' ';
    int result = move_r_b(a, move, 7, 0, 3, 0);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Horse, InCorrect_Knight_f)
{
    char move[6], a[N][M];
    move[0] = 'N';
    move[1] = 'b';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][1] = 'n';
    a[2][0] = 'K';
    int result = move_n_w(a, move, 0, 1, 2, 0);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Horse, InCorrect_Knight_h)
{
    char move[6], a[N][M];
    move[0] = 'N';
    move[1] = 'b';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][1] = 'N';
    a[5][0] = ' ';
    int result = move_n_b(a, move, 7, 1, 5, 0);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Bishop, InCorrect_Bishop_f)
{
    char move[6], a[N][M];
    move[0] = 'B';
    move[1] = 'c';
    move[2] = '1';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '3';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][2] = 'b';
    a[2][0] = ' ';
    int result = move_b_w(a, move, 0, 2, 2, 0);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Bishop, InCorrect_Bishop_h)
{
    char move[6], a[N][M];
    move[0] = 'B';
    move[1] = 'c';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'a';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][2] = 'B';
    a[5][0] = ' ';
    int result = move_b_b(a, move, 7, 2, 5, 0);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_Queen, InCorrect_Queen_h)
{
    char move[6], a[N][M];
    move[0] = 'Q';
    move[1] = 'd';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'd';
    move[5] = '2';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][3] = 'Q';
    a[1][3] = ' ';
    int result = move_q_b(a, move, 7, 3, 1, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_Queen, InCorrect_Queen_f)
{
    char move[6], a[N][M];
    move[0] = 'Q';
    move[1] = 'd';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'd';
    move[5] = '2';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][3] = 'q';
    a[1][3] = 'K';
    int result = move_q_w(a, move, 0, 3, 1, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(W_King, InCorrect_King_f)
{
    char move[6], a[N][M];
    move[0] = 'K';
    move[1] = 'e';
    move[2] = '1';
    move[3] = '-';
    move[4] = 'd';
    move[5] = '2';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[0][4] = 'k';
    a[1][3] = 'K';
    int result = move_k_w(a, move, 0, 4, 1, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(B_King, InCorrect_King_h)
{
    char move[6], a[N][M];
    move[0] = 'K';
    move[1] = 'e';
    move[2] = '8';
    move[3] = 'x';
    move[4] = 'd';
    move[5] = '7';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[7][4] = 'K';
    a[6][3] = ' ';
    int result = move_k_b(a, move, 7, 4, 6, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
