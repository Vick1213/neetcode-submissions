use std::collections::HashSet;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        if n == 0 {
            return 0;
        }

        let mut set: HashSet<char> = HashSet::new();
        let mut left: usize = 0;
        let mut right: usize = 0;
        let mut best: usize = 0;

        while right < n {
            
            while set.contains(&chars[right]) {
                set.remove(&chars[left]);
                left += 1;
            }
            set.insert(chars[right]);
            right += 1;

            best = best.max(right - left);
        }

        best as i32
    }
}