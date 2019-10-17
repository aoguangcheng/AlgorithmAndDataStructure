#include<stdio.h>

int main()
{
	int sum = 0;
	for(int A = 1; A <= 9; A++)
	{
		for(int B = 1; B <= 9; B ++)
		{
			for(int C = 1; C <= 9; C++)
			{
				for(int D = 1; D <= 9; D ++)
				{
					for(int E = 1; E <= 9; E++)
					{
						for(int F = 1; F <= 9; F++)
						{
							for(int G = 1; G <= 9; G++)
							{
								for(int H = 1; H <= 9; H++)
								{
									for(int I = 1 ; I <= 9; I++)
									{
										if(B * (100 * G +10* H + I) + C * (100 * D + 10 * E + F) == (10 - A)  * C*(100 *G+10*H+I) && A != B && A!= C && A != D && A != E && A != F && A!= G && A != H && A != I && B != C && B != D && B != E && B != F&&B != G&&B != H && B!= I && C != D && C != E && C != F && C != G && C!= H && C !=I&&  D != E && D != F && D != G && D != H && D != I&& E != F && E != G&& E!= H && E!= I && F != G && F !=H && F != I&& G != H && G!= I && H != I)
										{
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}