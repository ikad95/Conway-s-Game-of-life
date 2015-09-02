#!/bin/bash
yt="https://www.youtube.com/watch?v="
url="$(<ytube.txt)"

echo "Agent"
echo "$(<asciiart)"
echo "Ready!"

if [[ $url == *"$yt"* ]]
	then
		youtube-dl "$url";
fi
