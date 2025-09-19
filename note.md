
# Brainstroming for serialized hook data

function id : cstring

depth: uint32
argument {
    arg1 {
        byte: len uint64
        data: byte[]
    }
    arg2 {
        data: byte[]
    }
    .
    .
    .
    .
    .
}


time: double/real64
returns {
    return1 {
        data: byte[]
    }
    return2 {
        data: byte[]
    }
    .
    .
    .
}

