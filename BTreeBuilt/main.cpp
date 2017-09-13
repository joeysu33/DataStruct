/*!
  1.要求根据二叉树的中序和后序推算出前序
  2.要求根据二叉树的前序和中序推算出后序
  3.计算出所有的叶子节点
  4.计算树的高度（深度）
*/

#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

void BuildTree_ByInOrderAndPostOrder(char *in, char *post, char *out_pre, int length) {
    if(!in || !post || !out_pre) return ;
    if(length <= 0) return;

    int in_splitPos = 0;
    char pc = post[length-1];
    if(length == 1)
        printf("[%c] ", pc);
    else
        printf("%c ", pc);

    char *p = in;
    while(*p != pc && *p != 0) {
        in_splitPos++;
        ++p;
    }

    BuildTree_ByInOrderAndPostOrder(in, post, out_pre,in_splitPos);
    BuildTree_ByInOrderAndPostOrder(in + in_splitPos + 1, post + in_splitPos, out_pre, length - in_splitPos - 1);
}

void BuildTree_ByInOrderAndPreOrder(char *in, char *pre, char *out_post, int length) {
    if(!in || !pre || !out_post) return;
    if(length <= 0) return;

    int in_splitPos = 0;
    char *p = in;
    while(*p != pre[0] && *p != 0) {
        in_splitPos++;
        p++;
    }

    assert(in_splitPos >= 0);
    //左子树
    BuildTree_ByInOrderAndPreOrder(in, pre+1, out_post, in_splitPos );
    //右子树
    BuildTree_ByInOrderAndPreOrder(in+in_splitPos+1, pre+in_splitPos+1, out_post, length-in_splitPos-1);

    if(length == 1)
        printf("[%c] ", pre[0]);
    else
        printf("%c ", pre[0]);
}

int main()
{
    char *pre = "GDAFEMHZ";
    char *in = "ADEFGHMZ";
    char out_post [9];
    out_post[8] = 0;
    BuildTree_ByInOrderAndPreOrder(in, pre, &out_post[0], 8);
    cout<<endl<<"========================================="<<endl;

    char *post = "AEFDHZMG";
    BuildTree_ByInOrderAndPostOrder(in, post, pre, 8);

    return 0;
}
