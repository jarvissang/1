// SPDX-License-Identifier: MIT
pragma solidity ^0.8.18;

contract SimpleBank {
    // Tracks the balance of each address
    mapping(address => uint) public balances;

    // Deposit: Adds the sent ETH to the sender's balance
    function deposit() public payable {
        balances[msg.sender] += msg.value;
    }

    // Withdraw: Allows the sender to take out their ETH
    function withdraw(uint _amount) public {
        require(balances[msg.sender] >= _amount, "Insufficient balance");
        balances[msg.sender] -= _amount;
        
        // Send the ETH back to the user
        (bool success, ) = msg.sender.call{value: _amount}("");
        require(success, "Transfer failed");
    }

    // Balance Display: Shows the balance of a specific address
    function getBalance(address _user) public view returns (uint) {
        return balances[_user];
    }
}
