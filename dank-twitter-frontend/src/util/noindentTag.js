export default function noindent (strings, ...values) {
    function * separatorGenerator () {
        for (let sep of values)
            yield sep
    }

    const separator = separatorGenerator()

    const trimmedStrings = strings.map(string => string.replace(/\ {2,}/, ''))
    return trimmedStrings.reduce((accumulator, value) => accumulator + separator.next().value + value)
}