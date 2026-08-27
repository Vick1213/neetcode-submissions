impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
	// Define the upper bound for the binary search 
	let top_k: i32 = piles.iter().copied().max().expect("Piles will have values");

	let mut l = 1;
	let mut r = top_k + 1;
	
	while l < r {
		let mid = l + (r - l) / 2;
		if can_finish(&piles, h, mid) {
			r = mid;
		} else { 
			l = mid + 1; 
		}
	}

	l
    }
}

fn can_finish(piles: &[i32], h: i32, k: i32) -> bool {
	let mut hours = 0;	

	for pile in piles {
		hours += (pile + k -1 ) / k;
		if hours > h {
			return false;
		}
	}

	true
}
