#include <stdint.h>
#include <stdio.h>

    uint32_t half_add(uint32_t a, uint32_t b) {
        if (b == 0) return a;
        uint32_t sum = a ^ b;             /* 相加但不進位 */
        uint32_t carry = (a & b) << 1;    /* 進位但不相加 */
        return half_add(sum, carry);
    }
    uint32_t func(uint32_t x) {
	    uint32_t n = x;
    	n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    	n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
    	n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
    	n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
    	n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
    	return n;
	}
    uint32_t multi(uint32_t multiplier,uint32_t multiplicand,uint32_t product,uint32_t count,uint32_t tmpproduct){
        if((multiplicand == 0)){return 0;}
       	//利用count來算執行了幾次
		count=half_add(count,1);
		//printf("cnt=%d\n",count);
		uint32_t test=(multiplier & 0x00000001);
		//printf("multiplier=%d,test=%d\n",multiplier,test);
		if(test == 1){
			product=half_add(product,multiplicand);
			//printf("count=%d,product=%lu\n",count,product);
		}
		multiplier = multiplier >> 1;
		uint32_t tmp=(product & 0x00000001);
		tmp=func(tmp);
		tmpproduct=(tmpproduct >>1 ) | tmp;
		product =product >> 1;
		if(count!=32){
		return multi(multiplier,multiplicand,product,count,tmpproduct);
		}
        return tmpproduct;

    }
    int main(){
        uint32_t multiplier,multiplicand,count=0;
		uint32_t product=0,tmpproduct=0;
		puts("Please enter to numbers:");
		scanf("%d",&multiplier);
        scanf("%d",&multiplicand);
		// x = a * b;if (a != 0 && x / a != b) {overflow handling}
		product=multi(multiplier,multiplicand,product,count,tmpproduct);
        printf("product=%d",product);
        return 0;
    }
