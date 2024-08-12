#include "ArrayStack.h"
#include <iostream>


int main()
{
    ArrayStack<int> st(5);
    st.push(2);
    st.push(4);
    st.push(5);

    std::cout << st.peek(3) << '\n';
}
