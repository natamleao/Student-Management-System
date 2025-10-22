"""Functions to keep track and alter inventory."""


def create_inventory(items):
    """Create a dict that tracks the amount (count) of each element on the `items` list.

    :param items: list - list of items to create an inventory from.
    :return: dict - the inventory dictionary.
    """

    return dict(list(dict.fromkeys(map(lambda x: (x, items.count(x)), items))))

#
#    _dict = {}
#
#    for item in items:
#        if item not in _dict.keys():
#            _dict[item] = items.count(item)
#
#    return _dict

def add_items(inventory, items):
    """
    Add or increment items in inventory using elements from the items list.

    :param inventory: dict - dictionary of existing inventory.
    :param items: list - list of items to update the inventory with.
    :return: dict - the inventory updated with the new items.
    """
    _dict = inventory.copy()

    for item in items:
        _dict[item] = _dict.get(item, 0) + 1

    return _dict
    
def decrement_items(inventory, items):
    """Decrement items in inventory using elements from the `items` list.

    :param inventory: dict - inventory dictionary.
    :param items: list - list of items to decrement from the inventory.
    :return: dict - updated inventory with items decremented.
    """

    for item in items:
        if inventory.get(item, 0) > 0:
            inventory[item] -= 1

    return inventory

def remove_item(inventory, item):
    """Remove item from inventory if it matches `item` string.

    :param inventory: dict - inventory dictionary.
    :param item: str - item to remove from the inventory.
    :return: dict - updated inventory with item removed. Current inventory if item does not match.
    """

    if item in inventory.keys():
        inventory.pop(item)

    return inventory

def list_inventory(inventory):
    """Create a list containing only available (item_name, item_count > 0) pairs in inventory.

    :param inventory: dict - an inventory dictionary.
    :return: list of tuples - list of key, value pairs from the inventory dictionary.
    """

    _list = []

    for key, value in inventory.items():
        if value > 0:
            _list.append((key, value))

    return _list