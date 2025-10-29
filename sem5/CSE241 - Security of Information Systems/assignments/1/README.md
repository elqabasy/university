# CSE241 - Security of Information Systems Lab Assignment

## Exercise Solutions

### 7.1 - Exercise Set (20 minutes)

#### Demo Recordings
- **Exercise 1 - Computer SHA256 hases**: 
[![asciicast](https://asciinema.org/a/zr1Xuq0hzAEcf730JgKJoMohO.svg)](https://asciinema.org/a/zr1Xuq0hzAEcf730JgKJoMohO)
- **Exercise 2 - Modify one Byte**:
[![asciicast](https://asciinema.org/a/SyTwNzwPXOUc78MPNpmq9Dd0e.svg)](https://asciinema.org/a/SyTwNzwPXOUc78MPNpmq9Dd0e)
- **Exercise 3 - Compare SHA256 and SHA512 speeds**:
[![asciicast](https://asciinema.org/a/TypRu8VEXeISdPfBRao3yBe4n.svg)](https://asciinema.org/a/TypRu8VEXeISdPfBRao3yBe4n)

### Implementation Details

#### Exercise 1: SHA-256 Hash Computation
- **Python Implementation**: Uses `hashlib` library for SHA-256 hashing
- **C++ Implementation**: Uses OpenSSL's SHA-256 functions
- **Verification**: Both implementations produce identical hash values

#### Exercise 2: Avalanche Effect Demonstration
- Modified one byte in the test file
- Re-computed SHA-256 hash
- Analyzed bit changes in the resulting hash

#### Exercise 3: Performance Comparison
- Benchmarking script comparing SHA-256 vs SHA-512
- Measures hash computation speed for different data sizes
- Results show performance characteristics on the test system

#### Exercise 4: SHAttered Attack Research
- Analysis of Google's SHA-1 collision attack
- Details about the two different PDF files with identical SHA-1 hashes
- Implications for hash function security

## 7.2 - Quiz Solutions

### 1. Three Main Security Properties of Hash Functions
1. **Pre-image Resistance**: Given a hash value h, it should be computationally infeasible to find any message m such that h = hash(m)
2. **Second Pre-image Resistance**: Given an input m1, it should be computationally infeasible to find a different input m2 such that hash(m1) = hash(m2)
3. **Collision Resistance**: It should be computationally infeasible to find two different messages m1 and m2 such that hash(m1) = hash(m2)

### 2. Why SHA-1 is No Longer Recommended
SHA-1 is considered cryptographically broken due to:
- Theoretical vulnerabilities discovered as early as 2005
- Practical collision attack demonstrated by Google in 2017 (SHAttered attack)
- NIST deprecated SHA-1 in 2011 and disallowed its use after 2013

### 3. Why SHA-256 Can't Be Used Directly for Password Storage
- SHA-256 is fast to compute, making brute-force attacks practical
- No salt is used, allowing rainbow table attacks
- No key stretching, making GPU/ASIC attacks efficient
- **Solution**: Use dedicated password hashing functions like bcrypt, Argon2, or PBKDF2

### 4. Avalanche Effect
The avalanche effect is a property where a small change in input (even one bit) causes a significant change in the output hash (approximately 50% of bits change). This ensures that similar inputs produce completely different hashes.

### 5. Difference Between SHA-256 and HMAC-SHA256
- **SHA-256**: A cryptographic hash function that takes input and produces a fixed-size output
- **HMAC-SHA256**: A keyed-hash message authentication code that uses SHA-256 as the underlying hash function but includes a secret key for authentication


## Additional Resources
- [std::fmt](https://fmt.dev/12.0/)
- [Python hashlib Documentation](https://docs.python.org/3/library/hashlib.html)
- [SHAttered Attack Website](https://shattered.io/)

-- Mahros AL-Qabasy
