impl Solution {
    pub fn min_insertions(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut st: Vec<char> = Vec::new();
        let mut res = 0;
        let mut i = 0;

        while i < bytes.len() {
            let ch = bytes[i] as char;

            if ch == '(' {
                st.push(ch);
            } else {
                if st.is_empty() {
                    if i < bytes.len() - 1 && bytes[i + 1] as char == ')' {
                        i += 1;
                    } else {
                        res += 1;
                    }
                    res += 1;
                } else {
                    if i < bytes.len() - 1 && bytes[i + 1] as char == ')' {
                        i += 1;
                    } else {
                        res += 1;
                    }
                    st.pop();
                }
            }
            i += 1;
        }

        return res + (st.len() * 2) as i32;
    }
}
