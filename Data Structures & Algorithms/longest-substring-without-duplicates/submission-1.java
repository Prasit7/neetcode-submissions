//import java.util.Hashset;
class Solution {
    public int lengthOfLongestSubstring(String s) 
    {
       HashSet<Character> set = new HashSet<>();

        int left = 0;
        int maxLength = 0;
        //loop through char
        for (int right = 0; right < s.length(); right++) {
            //update left so that there are no duplicates
            while (set.contains(s.charAt(right))) {
                set.remove(s.charAt(left));
                left++;
            }
            //add this to hashSet
            set.add(s.charAt(right));
            //update max length
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
