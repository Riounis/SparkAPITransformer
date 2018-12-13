def lpad(str: String, len: Int, pad: String) = {
    if(str.length >= len) {
        str.substring(0, len)
    } else {
        var result: String = ""
        while(result.length + pad.length < len - str.length) {
          result += pad
        }
        result + pad.substring(0, len-result.length-str.length) + str
    }
}
