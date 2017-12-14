<template>
    <div id='app-container'>
        <SearchBox @search='searchTweets'/>
        <div class='main-wrapper'>
            <Navigation type='back' @back='back' />
            <TweetView :url='url' />
            <navigation type='forward' @forward='forward' />
        </div>
        <ParsedText :imageUrls='imageUrls' />
    </div>
</template>

<script>
import TweetView from '@/components/TweetView.vue'
import SearchBox from '@/components/SearchBox.vue'
import Navigation from '@/components/Navigation.vue'
import ParsedText from '@/components/ParsedText.vue'

import generateTweetUrl from '@/util/generateTweetUrl'
import twitterSearch from '@/util/twitterSearch'
import fetchJsonp from 'fetch-jsonp'

export default {
    data: function () {
        return {
            statuses: [],
            idx: 0
        }
    },
    computed: {
        currentStatus: function () {
            return this.statuses[this.idx] || undefined
        },
        url: function () {
            const defaultUrl = 'https://twitter.com/lushsux/status/939980522410852354'
            if (this.currentStatus)
                return generateTweetUrl(this.currentStatus.id_str, 
                    this.currentStatus.user.screen_name)
            else
                return defaultUrl
        },
        imageUrls: function () {
            if (this.currentStatus && this.currentStatus.entities.media) {
                const iterable = this.currentStatus.extended_entities
                    ? this.currentStatus.extended_entities.media
                    : this.currentStatus.entities.media
                return iterable.map(media => media.media_url)
            } else {
                return []
            }
        }
    },
    methods: {
        searchTweets: function (query) {
            twitterSearch({
                q: `${query} filter:images`,
                count: 100
            })
                .then(data => data.statuses)
                .then(statuses => this.statuses = statuses)
                .then(() => this.idx = 0)
        },
        back: function () {
            if (this.idx)
                this.idx--
        },
        forward: function () {
            if (this.idx < (this.statuses.length - 1))
                this.idx++
        }
    },
    components: {
        TweetView,
        SearchBox,
        Navigation,
        ParsedText
    }
}
</script>

<style lang='sass' scoped>
    @import '~@/global-styles/vars.sass'

    #app-container
        max-width: $app-container-width

        margin: auto
        padding: $app-container-padding

        display: flex
        align-items: center
        flex-direction: column
    
    .main-wrapper
        display: flex
        justify-content: center
        align-items: center

        width: 100%
</style>
