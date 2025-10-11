/*
Enter a charactor to store in an 8 bit register: A
01000001
Register after setting 3rd bit:
01000101
Register after clearing 6th bit:
01000101
Register after toggling first bit:
01000100
Final register value:
01000100
PS C:\EmbeddedSystemsProjectsEntri> ^C
PS C:\EmbeddedSystemsProjectsEntri>
PS C:\EmbeddedSystemsProjectsEntri>  & 'c:\Users\anees\.vscode\extensions\ms-vscode.cpptools-1.27.7-win32-x64\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-3av13nas.nbq' '--stdout=Microsoft-MIEngine-Out-k1lfbebp.rxf' '--stderr=Microsoft-MIEngine-Error-a0ficxdw.ewm' '--pid=Microsoft-MIEngine-Pid-pgmaw2ae.jb3' '--dbgExe=C:\msys64\ucrt64\bin\gdb.exe' '--interpreter=mi' 
Enter a charactor to store in an 8 bit register: a
01100001
Register after setting 3rd bit:
01100101
Register after clearing 6th bit:
01000101
Register after toggling first bit:
01000100
Final register value:
01000100
*/



#include<stdio.h>
unsigned char ch;
unsigned char *p = &ch;

void printReg(unsigned char *p)
{
    int i, mask=0;
    for (i=7; i>=0; i--)
    {
        mask = (1<<i);
        if ((*p)&mask)
        printf("1");
        else
        printf("0");
    }
}

void setBit (unsigned char *p, int i)
{
    
    (*p)|= (1<<(i-1));
    
    printf("\nRegister after setting 3rd bit: \n");
    printReg(&ch);

}

void clearBit (unsigned char *p, int i)
{
    (*p)&=~(1<<(i-1));
    printf("\nRegister after clearing 6th bit: \n");
    printReg(&ch);

}

void toggleBit(unsigned char *p, int i)
{
    int mask=0;
    mask=(1<<0);
    if (!((*p) & mask))
    ch|=(1<<0);
    else
    (*p)&=~(1<<0);
    printf("\nRegister after toggling first bit: \n");
    printReg(&ch);
}

int main()
{
    int i;
    printf("Enter a charactor to store in an 8 bit register: ");
    scanf(" %c", &ch);

    printReg(&ch); // prints the original register with the charactor's binary value

    // Set the 3rd bit (bit index 2)
    setBit(&ch, 3);

    // Clear the 6th bit (bit index 5)
    clearBit(&ch, 6);

    // Toggle the 1st bit (bit index 0)
    toggleBit(&ch, 1);

    printf("\nFinal register value:\n");
    printReg(&ch);
}