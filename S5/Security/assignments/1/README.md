# GU/CSE241/A1

## Exercise Solutions

### 7.1 - Exercise Set (20 minutes)

<!-- #### Demo Recordings -->
<!-- Exercise 1 - Compute SHA256 hashes -->
[![asciicast](https://asciinema.org/a/zr1Xuq0hzAEcf730JgKJoMohO.svg)](https://asciinema.org/a/zr1Xuq0hzAEcf730JgKJoMohO?t=61:50)

<!-- **Exercise 2 - Modify one Byte** -->
[![asciicast](https://asciinema.org/a/SyTwNzwPXOUc78MPNpmq9Dd0e.svg)](https://asciinema.org/a/SyTwNzwPXOUc78MPNpmq9Dd0e?t=2:15)

<!-- **Exercise 3 - Compare SHA256 and SHA512 speeds** -->
[![asciicast](https://asciinema.org/a/TypRu8VEXeISdPfBRao3yBe4n.svg)](https://asciinema.org/a/TypRu8VEXeISdPfBRao3yBe4n?t=9:50)




#### Exercise 4: SHAttered Attack Research
- SHAttered is a Cryptanalyst for SHA1 that produced a two different pdfs witht he SAME SHA1-hash!
- This is becasue collisions in SHA1, you can seee the full paper here: shattered.io

## 7.2 - Quiz Solutions

### 1. Three Main Security Properties of Hash Functions
1. **Pre-image Resistance**: Given a hash value h, it should be computationally infeasible to find any message m such that h = hash(m)
2. **Second Pre-image Resistance**: Given an input m1, it should be computationally infeasible to find a different input m2 such that hash(m1) = hash(m2)
3. **Collision Resistance**: It should be computationally infeasible to find two different messages m1 and m2 such that hash(m1) = hash(m2)

### 2. Why SHA-1 is No Longer Recommended
- As i mentioned in Ex.4, google produced two diff. pdfs with the same sha1-hash, so it's broken, or has a problem in collission resisten.
- Also, Theoretical vulnerabilities discovered as early as 2005
- NIST deprecated SHA-1 in 2011 and disallowed its use after 2013 # that's logicaly the normal flow after shattered.io papers

### 3. Why SHA-256 Can't Be Used Directly for Password Storage
- I see that becasue the powerfull of todays super computers, we can make brute-force attacks on it.
- Also the SHA256 is fast to compute, so the brute force will be practical
- Also i we want to use it, we have to salt it for preventing rainbow attacks


### 4. Avalanche Effect
The avalanche effect is a property where a small change in input (even one bit) causes a significant change in the output hash (approximately 50% of bits change). This ensures that similar inputs produce completely different hashes.

### 5. Difference Between SHA-256 and HMAC-SHA256
- **SHA-256**: A cryptographic hash function that takes input and produces a fixed-size output
- **HMAC-SHA256**: A keyed-hash message authentication code that uses SHA-256 as the underlying hash function but includes a secret key for authentication


## Additional Resources
- [std::fmt](https://fmt.dev/12.0/)
- [Python hashlib Documentation](https://docs.python.org/3/library/hashlib.html)
- [SHAttered Attack Website](https://shattered.io/)

> *Mahros AL-Qabasy*
> *223106831*
