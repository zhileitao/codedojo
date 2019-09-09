/*
You are given a 2D array of characters, and a target string. Return whether or not the word target word exists in the matrix. Unlike a standard word search, the word must be either going left-to-right, or top-to-bottom in the matrix.
Example:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

Given this matrix, and the target word FOAM, you should return true, as it can be found going up-to-down in the first column.
*/

int check_row(char *str, int len, current_row, char *w)
{
        int i, j;
        if (!str || !w) return 0;
        if (len < strlen(w)) return 0;
        for (i=0; i<len-strlen(w); i++) {  // here, can be improved to be i += j, which means start from the place where the difference begins
                for (j=0; j<strlen(w); j++) {
                        if (w[j] != str[current_row][i+j])
                                break;
                        if (j = strlen(w) -1)
                                return 1;
                }
        }
        return 0;
}

int check_col(char **str, int len, int current_col, char *w)
{
        int i, j;
        if (!str || !w) return 0;
        if (len < strlen(w)) return 0;
        for (i=0; i<len-strlen(w); i++) { // here, can be improved to be i += j, which means start from the place where the difference begins
                for (j=0; j<strlen(w); j++) {
                        if (w[j] != str[i+j][current_col])
                                break;
                        if (j == strlen(w) - 1)
                                return 1;
                }
        }
        return 0;
}

int world_search(char **A, int row_len, int col_len, char *w)
{
        int i;
        if (!A || !w) return 0;
        /* check each row */
        for (i=0; i<row_len; i++)
                if (check_row(A[i], col_len, i, w))
                        return 1;
        /* check each col */
        for(i=0; i<col_len; i++)
                if (check_col(A, row_len, i, w))
                        return 1;
        return 0;
}
