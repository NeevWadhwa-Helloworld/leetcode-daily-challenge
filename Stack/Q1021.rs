impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut res: Vec<char> = Vec::new();
        let mut stack: Vec<char> = Vec::new();
        
        for c in s.chars() {
            if c == ')' {
                stack.pop();
            }
            if !stack.is_empty() {
                res.push(c);
            }
            if c == '(' {
                stack.push(c);
            }
        }
        
        res.into_iter().collect()
    }
}
