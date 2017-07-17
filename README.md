# bitwiseMultiplier
### Q2: 在 C 程式中，使用遞迴和 bit-wise operator 來實作乘法運算，請參考以下提示
```clike
半加器可用以下 C 程式來實作:
uint32_t half_add(uint32_t a, uint32_t b) {
    if (b == 0) return a;
    uint32_t sum = a ^ b;             /* 相加但不進位 */
    uint32_t carry = (a & b) << 1;    /* 進位但不相加 */
    return half_add(sum, carry);
}
```
