bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char current = board[i][j];
            
            if (current == '.') {
                continue;
            }
            
            int val = current - '1';
            int mask = 1 << val;
            
            int box_idx = (i / 3) * 3 + (j / 3);
            
            if ((rows[i] & mask) || (cols[j] & mask) || (boxes[box_idx] & mask)) {
                return false;
            }
            
            rows[i] |= mask;
            cols[j] |= mask;
            boxes[box_idx] |= mask;
        }
    }
    
    return true;
}
