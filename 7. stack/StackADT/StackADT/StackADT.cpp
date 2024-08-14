#include "LinkedListStack.h"
#include <iostream>


int main()
{
    LinkedListStack<int> st;
    st.push(2);
    st.push(4);
    st.push(5);

    std::cout << st.peek(2) << '\n';
    st.display();
}
