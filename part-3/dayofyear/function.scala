def dayofyear(date: String) = {
    val months = Array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
    val month = Integer.parseInt(date.substring(5, 7))
    var days = 0
    for(i <- 0 to month - 2) {
        days += months(i)
    }
    days += Integer.parseInt(date.substring(8, 10))
    val year = Integer.parseInt(date.substring(0,4))
    if( month > 2 && year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                days + 1
            } else {
                days
            }
        } else {
            days + 1 
        }
    } else {
        days
    }
}
