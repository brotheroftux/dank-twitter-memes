<template>
    <pre>
        {{ text }}
    </pre>
</template>

<script>
import Tesseract from 'tesseract.js'

const grayscaleAPI = 'http://localhost:8008/grayscale'

const headers = {
        'Content-Type': 'application/json'
}

export default {
    props: ['imageUrl'],
    data: function () {
        return {
            imageBlob: undefined,
            text: 'Parsing image...',
        }
    },
    watch: {
        imageUrl: function () {
            this.fetchImageBlob()
        }
    },
    methods: {
        fetchImageBlob: function () {
            console.log('fetchin')
            const body = JSON.stringify({
                url: this.imageUrl
            })

            fetch(grayscaleAPI, {
                method: 'POST',
                body,
                headers
            })
                .then(response => response.blob())
                .then(blob => this.imageBlob = blob)
                .then(() => this.parseBlob())
        },
        parseBlob: function () {
            Tesseract.recognize(this.imageBlob, {
                lang: 'rus'
            })
                .progress(console.log)
                .then(result => this.text = result.text)
        }
    }
}
</script>

<style>

</style>
