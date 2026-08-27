impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut left = 1;
        let mut right = *piles.iter().max().unwrap();

        while left < right {
            let mid = left + (right - left) / 2;

            let hours: i64 = piles
                .iter()
                .map(|&pile| ((pile + mid - 1) / mid) as i64)
                .sum();

            if hours <= h as i64 {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left
    }
}
