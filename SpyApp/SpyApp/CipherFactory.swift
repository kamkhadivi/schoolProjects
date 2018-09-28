import Foundation

struct CipherFactory {

    private var ciphers: [String: Cipher] = [
        "Ceasar": CeaserCipher(),
        "Alphanumeric": AlphaNumericCipher(),
        "Unicode": UnicodeCipher()
        ]

    func cipher(for key: String) -> Cipher {
        return ciphers[key]!
    }
}
