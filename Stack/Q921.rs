impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut open_brackets=0;
        let mut min_adds_required=0;
        for c in s.chars(){
            if c=='('{
                open_brackets=open_brackets+1;
            }else{
                if(open_brackets>0){
                    open_brackets=open_brackets-1;
                }else{
                    min_adds_required=min_adds_required+1;
                }
            }
        }
        return min_adds_required+open_brackets;
    }
}
