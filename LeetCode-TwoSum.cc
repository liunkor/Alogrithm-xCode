/**
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/

    vector<int> twoSum(vector<int> &numbers, int target) {  
        /*
            1、复制一个数组，对复制的数组进行从小到大的排序，同时从数组的前端与后端寻找两个数之He等于target的两个数。
            2、根据两个数用算法find在原来的数组中找到这两个数的下标，然后对两给下标做相应的处理
        */
        
        vector<int> num(numbers); 
		vector<int> result;
		int sum =0;
	   	sort(num.begin(), num.end());
		int beg = 0; 
		int end = num.size() - 1;
		
		while(beg <= end) {
			sum = num[beg] + num[end];
			if(target == sum) 
				break;
			else if(target < sum) 
				end--;
			else 
				beg++;
		}

		if(beg < end) {
			auto i1 = find(numbers.begin(), numbers.end(), num[beg]);
			auto index1 = i1 - numbers.begin();
			result.push_back(index1+1);
			vector<int>::iterator i2;
			if(num[beg] != num[end])
				i2 = find(numbers.begin(), numbers.end(), num[end]);
			else 
				i2 = find(i1 + 1, numbers.end(), num[end]);
			
			auto index2 = i2 - numbers.begin();
			result.push_back(index2 + 1);
			if(result[0] > result[1]) 
				std::swap(result[0], result[1]);
		}
		return result;
    } 
