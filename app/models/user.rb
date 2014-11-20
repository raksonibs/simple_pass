class User < ActiveRecord::Base
  authenticates_with_sorcery!

  validate :password_is_equal

  def password_is_equal
    if password != '3421'
      errors.add(:password, 'inputted was incorrect')
    end
  end
end