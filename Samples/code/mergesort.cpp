typedef vector<int>::iterator vec_it;

void merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers)
{
    while (left != left_end)
    {
        if (*left < *right || right == right_end)
        {
            *numbers = *left;
            ++left;
        }
        else
        {
            *numbers = *right;
            ++right;
        }

        ++numbers;
    }

    while (right != right_end)
    {
        *numbers = *right;
        ++right;
        ++numbers;
    }
}

void merge_sort(vector<int> &numbers)
{
    if (numbers.size() <= 1)
        return;

    vector<int>::size_type middle = numbers.size() / 2;
    vector<int> left(numbers.begin(), numbers.begin() + middle);
    vector<int> right(numbers.begin() + middle, numbers.end());

    merge_sort(left);
    merge_sort(right);

    merge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin());
}