<template>
    <pre>{{ text }}</pre>
</template>

<script>
import Tesseract from 'tesseract.js'

import noindent from '@/util/noindentTag'

const grayscaleAPI = 'http://localhost:8008/grayscale'

const headers = {
        'Content-Type': 'application/json'
}

const defaultText = 'Images not found in tweet.'

export default {
    props: ['imageUrls'],
    data: function () {
        return {
            text: defaultText,
        }
    },
    watch: {
        imageUrls: function () {
            const textPromises = this.imageUrls.map(this.fetchImageBlob)

            Promise.all(textPromises)
            .then(values => values.join('\n'))
            .then(text => {
                console.log(text.length)
                this.text = text.length ? text : defaultText
            })
        }
    },
    methods: {
        fetchImageBlob: function (url) {
            this.text = 'Image(s) found, fetching...'

            const body = JSON.stringify({ url })

            return new Promise((resolve, reject) => {
                fetch(grayscaleAPI, {
                    method: 'POST',
                    body,
                    headers
                })
                .then(response => response.blob())
                .then(blob => this.parseBlob(blob, resolve, reject))
                .catch(error => reject(error))
            })
        },
        parseBlob: function (blob, resolve, reject) {
            const readableStatus = 'Image(s) found, parsing...'
            this.text = readableStatus
            // Tesseract.detect(blob).then(console.log)
            Tesseract.recognize(blob, {
                lang: 'rus'
            })
            .progress(progress => {
                this.text = noindent`${readableStatus}
                    ${progress.status} ${progress.progress * 100 | 0}%`
            })
            .then(result => resolve(result.text))
            .catch(error => reject(error))
        }
    }
}
</script>

<style lang='sass' scoped>
    @import '~@/global-styles/vars.sass'

    pre
        min-height: $parsed-min-height
        width: 100%
        padding: $parsed-padding

        border-radius: $parsed-border-radius
        background-color: $parsed-background

        font-family: $parsed-font
</style>
