void merge(int *vec, int start, int end)
{
    if (start >= end) return;
    int mid = start + ((end - start) >> 1);
    merge(vec, start, mid);
    merge(vec, mid + 1, end);
    for (int i = start; i <= mid; i++)
    {
        //ans += distance(lower_bound(vec + mid + 1, vec + end + 1, vec[i] + lower),
        //                upper_bound(vec + mid + 1, vec + end + 1, vec[i] + upper));
        //Do some cool stuffs
    }
    inplace_merge(vec + start, vec + mid + 1, vec + end + 1);
}
