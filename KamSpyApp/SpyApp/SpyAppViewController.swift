import UIKit

class SpyAppViewController: UIViewController {

    @IBOutlet weak var input: UITextField!
    @IBOutlet weak var secret: UITextField!
    @IBOutlet weak var output: UILabel!

    let factory = CipherFactory()
    var cipher: Cipher?

    var plaintext: String {
        if let text = input.text {
            return text
        } else {
            return ""
        }
    }

    var secretText: String {
        if let text = secret.text {
            return text
        } else {
            return ""
        }
    }

    @IBAction func encodeButtonPressed(_ sender: UIButton) {
        guard let cipher = self.cipher else {
            output.text = "No cipher selected"
            //output.text = "\u{1800}"
            return
        }
        if let encoded = cipher.encode(plaintext, secret: secretText) {
            output.text = encoded
        } else {
            output.text = "Error encoding"
        }
    }
    
    @IBAction func decodeButtonPressed(_ sender: UIButton) {
      
        guard let cipher = self.cipher else {
            output.text = "Encrypt code first, then you can decrypt"
            return
        }
        if let cipher = self.cipher{
            output.text = cipher.decrypt(output.text!, secret: self.secret.text!)
        }else{
            output.text = "no cipher selected"
        
        }
    }
    
        
    @IBAction func cipherButtonPressed(_ sender: UIButton) {
        guard
            let buttonLable = sender.titleLabel,
            let buttonText = buttonLable.text
        else {
            output.text = "Missing text and/or secret"
            return
        }
        cipher = factory.cipher(for: buttonText)
    }
    
}


