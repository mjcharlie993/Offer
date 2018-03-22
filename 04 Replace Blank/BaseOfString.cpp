int main()
{
    char str1[] = "Hello World";
    char str2[] = "Hello World";

    char* str3 = "Hello World";
    char* str4 = "Hello World";

    if (str1 == str2)
        printf("str1 and str2 are same.\n");
    else
        printf("str1 and str2 are not same.\n");

    if (str3 == str4)
        printf("str3 and str4 are same.\n");
    else
        printf("str3 and str4 are nott same.\n");
}
Output: 
str1 and str2 are not same.
str3 and str4 are same.