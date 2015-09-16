class MergeSort:

    def msort(self, array, tmp_array, left, right):
        if left < right:
            center = (left+right)/2

            self.msort(array, tmp_array, left, center)
            self.msort(array, tmp_array, center + 1, right)
            self.merge(array, tmp_array, left, center + 1, right)

    def merge(self, array, tmp_array, left_pos, right_pos, right_end):
        tmp         = 0
        tmp_pos     = left_pos
        left_end    = right_pos - 1
        num_element = right_end - left_pos + 1;

        while left_pos <= left_end and right_pos <= right_end:
            if array[left_pos] <= array[right_pos]:
                tmp_array[tmp_pos] = array[left_pos]
                tmp_pos += 1
                left_pos += 1
            else:
                tmp_array[tmp_pos] = array[right_pos]
                tmp_pos += 1
                right_pos += 1

        tmp_array[tmp_pos:tmp_pos +(left_end  - left_pos) ] = array[left_pos :left_end+1]
        tmp_array[tmp_pos:tmp_pos +(right_end - right_pos)] = array[right_pos:right_end+1]
        array[right_end-num_element+1:right_end+1] = tmp_array[right_end-num_element+1:right_end+1]


#--------------test-----------------
s = MergeSort()
array       = [10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2]
tmp_array   = [0 for i in range(0, len(array))]
s.msort(array, tmp_array, 0, len(array)-1)
print tmp_array
print array