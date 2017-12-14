<template>
    <div class='tweet-preview' v-html='html'></div>
</template>

<script>
import querystring from 'querystring'
import fetchJsonp from 'fetch-jsonp'

const embed_api = 'https://publish.twitter.com/oembed?'

const data = {
    html: '<div>Loading tweet...</div>'
}

export default {
    props: ['url'],
    data: function () {
        return data
    },
    mounted: function () {
        this.tweetHtml()
    },
    watch: {
        url: function () {
            this.tweetHtml()
        }
    },
    methods: {
        tweetHtml: function () {
            const url = querystring.stringify({
                url: this.url
            })
            fetchJsonp(embed_api + url)
                .then(response => response.json())
                .then(json => {
                    this.html = json.html
                })
                .then(() => twttr.widgets.load())
        }
    }
}
</script>

<style lang='sass' scoped>
    @import '~@/global-styles/vars.sass'

    .tweet-preview
        display: flex
        justify-content: center
</style>

