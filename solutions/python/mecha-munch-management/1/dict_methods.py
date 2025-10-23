"""Functions to manage a users shopping cart items."""


def add_item(current_cart, items_to_add):
    """Add items to shopping cart.

    :param current_cart: dict - the current shopping cart.
    :param items_to_add: iterable - items to add to the cart.
    :return: dict - the updated user cart dictionary.
    """

    cart = current_cart.copy()

    for item in items_to_add:
        cart.setdefault(item, 0)
        cart[item] += 1

    return cart

def read_notes(notes):
    """Create user cart from an iterable notes entry.

    :param notes: iterable of items to add to cart.
    :return: dict - a user shopping cart dictionary.
    """

    return dict.fromkeys(notes, 1)

def update_recipes(ideas, recipe_updates):
    """Update the recipe ideas dictionary.

    :param ideas: dict - The "recipe ideas" dict.
    :param recipe_updates: iterable -  with updates for the ideas section.
    :return: dict - updated "recipe ideas" dict.
    """

    cart = ideas.copy()

    for key in recipe_updates:
        cart[key[0]] = dict(key[1])

    return cart

def sort_entries(cart):
    """Sort a users shopping cart in alphabetically order.

    :param cart: dict - a users shopping cart dictionary.
    :return: dict - users shopping cart sorted in alphabetical order.
    """

    return  dict(sorted(cart.items()))

def send_to_store(cart, aisle_mapping):
    fulfillment_cart = {}

    # Ordena as chaves do carrinho em ordem alfabética reversa
    for item in sorted(cart.keys(), reverse=True):
        quantity = cart[item]
        aisle, refrigerated = aisle_mapping[item]
        fulfillment_cart[item] = [quantity, aisle, refrigerated]  # <-- lista, não tupla

    return fulfillment_cart

def update_store_inventory(fulfillment_cart, store_inventory):
    """Update store inventory levels with user order.

    :param fulfillment cart: dict - fulfillment cart to send to store.
    :param store_inventory: dict - store available inventory
    :return: dict - store_inventory updated.
    """
    
    fulfillment = store_inventory.copy()

    for key in fulfillment_cart.keys():
        if key in fulfillment:
            fulfillment[key][0] -= fulfillment_cart[key][0]
            if store_inventory[key][0] <= 0:
                fulfillment[key][0] = 'Out of Stock'

    return dict(sorted(fulfillment.items(), reverse=True))