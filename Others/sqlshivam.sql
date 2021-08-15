select channel.categoryid, channel.channelname, viewer.viewername from
(channel inner join programme on channel.channelid = programme.channelid)
inner join viewers on viewers.programmeid = channel.programmeid
where channel.categoryname <> "Sports" and channel.categoryname <> "Movies"