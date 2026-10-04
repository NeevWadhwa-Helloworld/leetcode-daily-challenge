impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut open_stack: Vec<usize> = Vec::new();
        let mut star_stack: Vec<usize> = Vec::new();

        for (i, ch) in s.chars().enumerate() {
            match ch {
                '(' => open_stack.push(i),
                '*' => star_stack.push(i),
                ')' => {
                    if open_stack.pop().is_some() {} else if star_stack.pop().is_some() {} else {
                        return false;
                    }
                }
                _ => {}
            }
        }
        while let (Some(&open_idx), Some(&star_idx)) = (open_stack.last(), star_stack.last()) {
            if open_idx < star_idx {
                open_stack.pop();
                star_stack.pop();
            } else {
                break;
            }
        }
        open_stack.is_empty()
    }
}
