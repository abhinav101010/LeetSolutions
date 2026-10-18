select
    round(
        ifnull(
            (
                select count(distinct l.sender_id, l.send_to_id)
                from friend_request l
                join friend_request r
                  on l.sender_id = r.send_to_id
                 and l.send_to_id = r.sender_id
            ) / 
            (
                select count(distinct sender_id, send_to_id)
                from friend_request
            )
        , 0)
    , 2) as accept_rate
