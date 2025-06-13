/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minimizeMax = function(nums, p) {
    nums.sort((a, b) => a - b);
    let low = 0, high = nums[nums.length - 1] - nums[0], res = high;
    const canForm = (mid) => {
        let count = 0;
        for (let i = 1; i < nums.length; ) {
            if (nums[i] - nums[i - 1] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    };
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (canForm(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
};
