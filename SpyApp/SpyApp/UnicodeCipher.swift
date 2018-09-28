//
//  UnicodeCipher.swift
//  SpyApp
//
//  Created by Kayhan Khadivi-Dimbali on 9/27/18.
//  Copyright © 2018 Axel Ancona Esselmann. All rights reserved.
//

import Foundation

struct UnicodeCipher: Cipher {
func encode(_ plaintext: String, secret: String) -> String? {
    var encoded = ""
    
    for character in plaintext {
        let unicode = character.unicodeScalars.first!.value
        let char = String(unicode)
        encoded = encoded + char
    }
    return encoded
}

func decrypt(_ encrypted: String, secret: String) -> String? {
    var decoded = ""
    
    for character in encrypted {
        let encrypted = character.unicodeScalars.first!.value
        let normalcharacter = String(UnicodeScalar(UInt8(encrypted)))
        decoded = decoded + normalcharacter
    }
    return decoded
}

}
