impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let mut stack: Vec<i32> = vec![0];

        for ch in s.chars() {
            if ch == '(' {
                stack.push(0);
            } else {
                let inside = stack.pop().unwrap();
                let score = if inside == 0 { 1 } else { 2 * inside };
                if let Some(top) = stack.last_mut() {
                    *top += score;
                }
            }
        }

        stack.pop().unwrap()
    }
}
