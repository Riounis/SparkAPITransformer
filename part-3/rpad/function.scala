def rpad(str: String, len: Int, pad: String) = {
    if(str.length <= len) {
        var result:String = str
        while(result.length + pad.length < len) {
            result += pad
        }
        result + pad.substring(0, len - result.length)
    } else {
        str.substring(0, len)
    }
}
