def concat_ws(sep: String, strings: String*) = {
    var result:String = ""
    for(s<-strings) {
        result += s + sep
    }
    result.substring(0, result.length-sep.length)
}
