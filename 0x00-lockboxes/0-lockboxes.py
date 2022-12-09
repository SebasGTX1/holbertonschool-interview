#!/usr/bin/python3
""" Task 0 Lockboxes """


def canUnlockAll(boxes):
    """ method that determines if all the boxes can be opened """
    boxes_unlocked = [0]
    for id, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in boxes_unlocked and key != id:
                boxes_unlocked.append(key)
    if len(boxes_unlocked) == len(boxes):
        return True
    return False
